using UnityEngine;
using System.Collections;

public class OtherPlayerController : MonoBehaviour {

	public float speed2;
	public float jumpSpeed;

	private Rigidbody rb;

	void Start ()
	{
		rb = GetComponent<Rigidbody>();
	}

	void FixedUpdate ()
	{
		float moveHorizontal = Input.GetAxis ("Horizontal2");
		float moveVertical = Input.GetAxis ("Vertical2");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		if (Input.GetKeyDown ("space"))
			movement.y = jumpSpeed;
		rb.AddForce (movement * speed2);
	}

}